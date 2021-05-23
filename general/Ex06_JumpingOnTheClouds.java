package hackerRank.general;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
Link:
https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup

Sample Input
6
0 0 0 0 1 0

Sample Input
6
0 0 0 1 0 0
 */


public class Ex06_JumpingOnTheClouds {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner ler = new Scanner(System.in);
		int n = ler.nextInt();
		ler.nextLine();

		List<Integer> c = new ArrayList<Integer>();

		for (int i = 0; i < n; i++) {
			c.add(ler.nextInt());
		}

		//		for (Integer item : c) {
		//			System.out.println(item);
		//		}

		System.out.println(jumpingOnClouds(c));

	}

	private static int jumpingOnClouds(List<Integer> c) {
		// TODO Auto-generated method stub
		int result = 0;
		int i = 0;
		boolean flagPulo2 = false;

		while (i < c.size()-1) {
			if ((flagPulo2) == false && (c.size() > 2)) {
				if(c.get(i+2) == 0){
					result++;
					i+=2;
					System.out.println("2 pulos: " + result);
					if (i == c.size()-2) {
						flagPulo2 = true;
					}
				} else if (c.get(i+1) == 0){
					result++;
					i+=1;
					System.out.println("1 pulo: " + result);
					if (i == c.size()-1) {
						return result;
					}
				} else {
					return result;
				}
			} else if (c.get(i+1) == 0){
				result++;
				i+=1;
				System.out.println("1 pulo: " + result);
				if (i == c.size()-1) {
					return result;
				}
			} else {
				return result;
			}

		}

		return result;


	}

}
