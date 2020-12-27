import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
    public static void main(String[] args)
    {
        List<BigInteger> prev = new ArrayList<>();
        List<BigInteger> next = new ArrayList<>();

        prev.add(BigInteger.valueOf(1));
        prev.add(BigInteger.valueOf(1));

        System.out.println("1");
        System.out.println("1 1");

        final BigInteger stoppingCond = BigInteger.valueOf(10).pow(60);

        while(true)
        {
            next.clear();
            next.add(BigInteger.valueOf(1));

            boolean stop = false;
            System.out.print("1 ");
            for(int i = 1; i < prev.size(); ++i)
            {
                BigInteger val = prev.get(i - 1).add(prev.get(i));
                next.add(val);
                if(val.compareTo(stoppingCond) >= 0)
                {
                    stop = true;
                }
                System.out.print(next.get(i) + " ");
            }

            next.add(BigInteger.valueOf(1));
            System.out.println("1");

            if(stop) 
            {
                break;
            }

            // swap
            List<BigInteger> temp = prev;
            prev = next;
            next = temp;
        }
    }
}
