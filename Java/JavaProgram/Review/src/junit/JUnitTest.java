package junit;

import junit.Calculator;
import org.junit.Assert;
import org.junit.Test;

public class JUnitTest {
    @Test
    public void testAdd() {
        Calculator cal = new Calculator();
        int result = cal.add(1,2);
        Assert.assertEquals(3, result);
    }
    @Test
    public void testSub(){
        Calculator cal = new Calculator();
        int result = cal.sub(1,2);
        Assert.assertEquals(-1,result);
    }
}
