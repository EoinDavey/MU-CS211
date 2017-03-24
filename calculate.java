import java.util.*;
import java.math.*;

public class calculate {

    BigInteger c1 = new BigInteger("147885907682256895");
    BigInteger c2 = new BigInteger("160453017523267545");
    BigInteger p = new BigInteger("167317834983028799");
    BigInteger x = new BigInteger("112410503608119");

    void run(){
        BigInteger inv = c1.modPow(p.subtract(BigInteger.ONE).subtract(x),p);
        BigInteger ans = inv.multiply(c2).mod(p);
        System.out.println(ans.toString());
    }

    public static void main(String[] args){
        calculate c = new calculate();
        c.run();
    }
}
