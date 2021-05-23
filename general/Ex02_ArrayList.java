package hackerRank.general;
import java.util.ArrayList;

import java.util.Scanner;


/*
Link:
https://www.hackerrank.com/challenges/java-arraylist/problem?h_r=profile

Sample Input
5
5 41 77 74 22 44
1 12
4 37 34 36 52
0
3 20 22 33
5
1 3
3 4
3 1
4 3
5 5
 */
public class Ex02_ArrayList {
	
	
	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		int n, d, q, x, y;
		ArrayList<ArrayList<Integer>> matrix = new ArrayList<ArrayList<Integer>>();
				
		n = ler.nextInt(); //2 linhas				
		
		for (int i = 0; i < n; i ++) {
			d = ler.nextInt(); //d colunas
			matrix.add(new ArrayList<Integer>());
			for (int j = 0; j < d; j ++) {
				int valor = ler.nextInt();
				ArrayList<Integer> linha = matrix.get(i);
				linha.add(valor);
			}			
		}
		//System.out.println(matrix);
		
		q = ler.nextInt();		
		for (int k = 0; k < q; k ++) {
			x = ler.nextInt();
			y = ler.nextInt();
			try {
				System.out.println(matrix.get(x-1).get(y-1));
			} catch (Exception e) {
				System.out.println("ERROR!");
			}				
		}		
	}	
		
	
	

//	public static void main(String[] args) {
//		Scanner ler = new Scanner(System.in);
//		int n, d, q, x, y;
//		ArrayList[] matrix = new ArrayList[2000];
//		
//				
//		n = ler.nextInt(); //2 linhas				
//		
//		for (int i = 0; i < n; i ++) {
//			d = ler.nextInt(); //3 colunas
//			matrix[i] = new ArrayList();			
//			for (int j = 0; j < d; j ++) {
//				int valor = ler.nextInt();
//				matrix[i].add(valor);
//			}
//			//matrix.add(i, linha);
//			
//		}
//		
//		for (int i = 0; i < n; i ++) {
//			System.out.println(matrix[i]);
//		}
//		
//		
//		
//	}
}
