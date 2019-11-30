public class ValueArg extends KernelArg {
    private byte type;

    private final static byte FLOAT = 1, INT = 2, DOUBLE = 3, BOOLEAN = 4;

    public static ValueArg create(float value){
        ValueArg arg = createInternal(value);
        arg.type = FLOAT;

        return arg;
    }

    public static ValueArg create(int value){
        ValueArg arg = createInternal(value);
        arg.type = INT;

        return arg;
    }

    public static ValueArg create(double value){
        ValueArg arg = createInternal(value);
        arg.type = DOUBLE;

        return arg;
    }

    public static ValueArg create(boolean value){
        ValueArg arg = createInternal(value);
        arg.type = BOOLEAN;

        return arg;
    }

    private static native ValueArg createInternal(float value);
    private static native ValueArg createInternal(int value);
    private static native ValueArg createInternal(double value);
    private static native ValueArg createInternal(boolean value);

    public float asFloat(){
        assert(type == FLOAT);

        return asFloatInternal();
    }

    public int asInt(){
        assert(type == INT);

        return asIntInternal();
    }

    public double asDouble(){
        assert(type == DOUBLE);

        return asDoubleInternal();
    }

    public boolean asBoolean(){
        assert(type == BOOLEAN);

        return asBooleanInternal();
    }

    private native float asFloatInternal();
    private native int asIntInternal();
    private native double asDoubleInternal();
    private native boolean asBooleanInternal();

    ValueArg(long handle){
        super(handle);
    }
}