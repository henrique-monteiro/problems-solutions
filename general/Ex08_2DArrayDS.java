package hackerRank.general;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/*
link:
https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

Sample Input
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0
 */

public class Ex08_2DArrayDS {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner ler = new Scanner(System.in);
		
		List<List<Integer>> arr = new ArrayList<>();		
		for (int i=0; i<6; i++) {
			List<Integer> arrAux = new ArrayList<>();
			for (int j=0; j<6; j++) {
				arrAux.add(ler.nextInt());				
			}
			arr.add(arrAux);
		}		
		//System.out.println(arr);	
		
		System.out.println(hourglassSum(arr));
		
	}

	private static int hourglassSum(List<List<Integer>> arr) {
		// TODO Auto-generated method stub
		int resultadoFinal = -999999999;
		int sum = 0;
		int maiorValorDaLinha;
		List<Integer> aux1 = new ArrayList<>();
		List<Integer> aux2 = new ArrayList<>();
		List<Integer> aux3 = new ArrayList<>();
		List<List<Integer>> result = new ArrayList<>();
		
		
		for(int i=0; i<4; i++) {
			aux1 = arr.get(i);
			aux2 = arr.get(i+1);
			aux3 = arr.get(i+2);
			List<Integer> arrAux = new ArrayList<>();
			for(int j=0; j<4; j++) {
				sum = 	aux1.get(j) + aux1.get(j+1) + aux1.get(j+2)
						+ aux2.get(j+1)
						+ aux3.get(j) + aux3.get(j+1) + aux3.get(j+2);
				arrAux.add(j, sum);
			}
			maiorValorDaLinha = Collections.max(arrAux);
			if (resultadoFinal < maiorValorDaLinha) {
				resultadoFinal = maiorValorDaLinha;
			}
		}
		//System.out.println(result);
		return resultadoFinal;
	}






}
