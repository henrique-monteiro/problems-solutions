package hackerRank.general;
import java.util.ArrayList;
import java.util.Scanner;


/*
Link:
https://www.hackerrank.com/challenges/handshake/problem
 
Sample Input
2
1
2
 */
public class Ex01_Handshake {

	private static Integer calculaRecursivamente(Integer elemento) {
		if (elemento == 1) {
			return 0;
		}

		else if (elemento == 2) {
			return 1;
		}

		else
			return elemento - 1 + calculaRecursivamente(elemento - 1);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner ler = new Scanner(System.in);
		int t = ler.nextInt();

		ArrayList<Integer> vetor = new ArrayList<Integer>();
		ArrayList<Integer> vetorResposta = new ArrayList<Integer>();

		for (int i = 0; i < t; i++) {
			vetor.add(ler.nextInt());
		}

		// System.out.println(vetor);

		for (Integer elemento : vetor) {
			vetorResposta.add(calculaRecursivamente(elemento));
		}

		System.out.println(vetorResposta);
	}

}
