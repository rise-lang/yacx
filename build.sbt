lazy val CUexecutor = (project in file("."))
  .settings(
    name    := "CUDA executor",
    scalaVersion := "3.1.2",
    version := "0.6.2",
    libraryDependencies += "junit" % "junit" % "4.13.2",

    compileOrder := CompileOrder.JavaThenScala,

    compile := ((Compile / compile) dependsOn buildExecutor).value,
    test    := ((Test / test) dependsOn buildExecutor).value
  )

lazy val buildExecutor = taskKey[Unit]("Builds C executor library")

buildExecutor := {
  import scala.language.postfixOps
  import scala.sys.process._
  //noinspection PostfixMethodCall
  "echo y" #| (baseDirectory.value + "/yacx.sh build-java") !
}
