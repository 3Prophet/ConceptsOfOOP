/**
 *@author Dmitry Logvinovich
 *@version 1.0
 *
 * This will hack data flow analyzer and bytecode verifier
 * of JVM because constructor of
 * Sub calls constructor of Demo implicitly and the latter calls size()
 * which is bound dynamicly to Sub::size, the latter in turn calls 
 * method on yet uninitialized field and voila...NullPtr exception
 */ 

import java.util.ArrayList;


public class Sub extends Demo 
{
    public ArrayList<?> data;

    public Sub(ArrayList<?> val) {
        data = val;
        size();
    }

    @Override
    public int size() {
        return data.size();
    }
}

