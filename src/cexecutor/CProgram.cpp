#include "../../include/yacx/cexecutor/CProgram.hpp"
#include "../../include/yacx/Logger.hpp"

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>

using yacx::loglevel, yacx::CProgram, yacx::detail::load_op, yacx::detail::unload_op, yacx::detail::dynop;

int CProgram::id = 0;

CProgram::CProgram(const char* cProgram, const char* functionName, int numberParameters,
        const char* compilerWithOptions) 
    : m_numberArguments(numberParameters) {
    logger(loglevel::DEBUG) << "creating cProgram " << functionName << " with id: " << id
    << ",number of arguments: " << numberParameters << ", compiler: " << compilerWithOptions;
    logger(loglevel::DEBUG1) << "cFunction:\n" << cProgram;

    id++;
    
    //filename for srcFile
    std::stringstream srcFileS;
    srcFileS << "src_" << functionName << "_" << id << ".c";
    m_srcFile = srcFileS.str().c_str();

    //filename for libFile
    std::stringstream libFileS; 
    libFileS << "lib_" << functionName << "_" << id << ".so";
    m_libFile = libFileS.str().c_str();

    logger(loglevel::DEBUG1) << "compile it to " << m_srcFile << " and " << m_libFile;

    //compile
    compile(cProgram, functionName, numberParameters, compilerWithOptions);

    //open libary
    load_op(&m_op, m_libFile);
}

CProgram::~CProgram() {
    logger(loglevel::DEBUG) << "destroy cProgram with id" << id;

    unload_op(&m_op);

    remove(m_srcFile);
    remove(m_libFile);
}

void CProgram::createSrcFile(const char* cProgram, const char* functionName, int numberParameters,
        std::ofstream& fileOut) {
    std::string executeFunctionName("execute");
    executeFunctionName.append(functionName);
    
    //write c function to be executed
    fileOut << cProgram;
    fileOut << "\n\n";
    
    //function for start function to be executed
    fileOut << "void " << executeFunctionName << " (";
    fileOut << "void** parameter";
    fileOut << ") {\n";
    //run function to be executed
    fileOut << "    " << functionName << "(";
    for (int i = 0; i < numberParameters-1; i++){
        fileOut << "parameter[" << i << "], ";
    }
    fileOut << "parameter[" << numberParameters-1 << "]";
    fileOut << ");\n";
    fileOut << "}\n\n";

    //struct to store function pointer
    fileOut << "struct opfn{ void (*op)(void** parameter);};\n\n";
    
    //create instance of struct as interface
    fileOut << "struct opfn op = {.op = " << executeFunctionName << "};\n";
}

void CProgram::compile(const char* cProgram, const char* functionName, int numberParameters,
        const char* compilerWithOptions) {
    logger(loglevel::DEBUG) << "creating source file...";

    //create and open output file
    std::ofstream fileOut;
    fileOut.open(m_srcFile);
    
    //write srcfile
    createSrcFile(cProgram, functionName, numberParameters, fileOut);
    
    //close file
    fileOut.close();

    //command for compile file
    std::stringstream compilerCommand;
    compilerCommand << compilerWithOptions << " -fPIC -shared -Wl,-soname," << m_libFile
        << " -o " << m_libFile << " " << m_srcFile;

    logger(loglevel::DEBUG) << "compiling to dynamic libary: " << compilerCommand.str();

    //compile to libary
    std::system(compilerCommand.str().c_str());
}

void CProgram::execute(void** arguments) {
    m_op.op(arguments);
}