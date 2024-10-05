import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;  // Import the Scanner class
import java.math.*;


public class Main {

	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);  // Create a Scanner object
		
		BigInteger n1 = BigInteger.ONE;
		BigInteger n2 = BigInteger.ONE;
		
		Integer n = scanner.nextInt();
		
		for(int i = 0; i<n; i+=1){
			Integer ai = scanner.nextInt();
			
			BigInteger cur = BigInteger.valueOf(ai);
			
			n1 = n1.multiply(cur);
		}
		
		Integer m = scanner.nextInt();
		
		for(int i = 0; i<m; i+=1){
			Integer bi = scanner.nextInt();
			
			BigInteger cur = BigInteger.valueOf(bi);
			
			n2 = n2.multiply(cur);
		}
		
		BigInteger res = n1.gcd(n2);
		
		String ans = res.toString();
		
		int len = ans.length();
		
		String out;
		
		if(len > 9){
			out = ans.substring(len-9);
		}
		else{
			out = ans;
		}
		
		System.out.println(out);
		
	}

}
