package hackerRank.pagSeguro;
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;


public class Ex11 {
	public static void main(String[] args) throws IOException {
		Scanner ler = new Scanner(System.in);
		
		System.out.println(minNum(ler.nextInt(), ler.nextInt(), ler.nextInt()));
	}

	public static int minNum(int samDaily, int kellyDaily, int difference) {
		// Write your code here
		int samSum;
		int kellySum;

		samSum = difference + samDaily;
		kellySum = kellyDaily;

		for (int i = 1; i < 100; i++){
			if (kellySum > samSum){
				return i;
			}
			samSum += samDaily;
			kellySum += kellyDaily;
		}
		return -1;

	}
}



