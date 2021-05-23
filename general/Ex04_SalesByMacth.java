package hackerRank.general;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


/*
Link:
https://www.hackerrank.com/challenges/sock-merchant/problem?h_r=profile

Sample Input
9
10 20 20 10 10 30 50 10 20
 */
public class Ex04_SalesByMacth {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner ler = new Scanner(System.in);

		int n = ler.nextInt();

		ArrayList<Integer> ar = new ArrayList<Integer>();

		for (int i = 0; i < n; i++) {
			ar.add(ler.nextInt());
		}

		int resultado = calcula(n, ar);

		System.out.println(resultado);
	}

	private static int calcula(int n, ArrayList<Integer> ar) {
		// TODO Auto-generated method stub

		Collections.sort(ar);

		//System.out.println(ar);

		int valorAtual = ar.get(0);
		int count = 0;

		for (int i = 1; i < n; i++) {			
			if(ar.get(i) == valorAtual) {
				count++;
				
				if(i < n-1) {
					valorAtual = ar.get(i + 1);
				}
				
				i++;
			}
			else {
				valorAtual = ar.get(i);

			}
		}	
		return count;
	}

}
