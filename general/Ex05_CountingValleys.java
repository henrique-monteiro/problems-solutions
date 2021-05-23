package hackerRank.general;

import java.util.Scanner;

/*
Link:
https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup

1- Sample Input
8
UDDDUDUU

2 - Sample Input
10
DUDDDUUDUU
 */


public class Ex05_CountingValleys {	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner ler = new Scanner(System.in);
		int steps = ler.nextInt();
		ler.nextLine();
		
		/*
		 * Basicamente, nextInt s� l� o m�nimo necess�rio para que se tenha um n�mero inteiro. Por isso ele n�o consome a quebra
		 * de linha (o ENTER que o usu�rio digita), e esta � consumida pela pr�xima chamada de nextLine (ou seja, o segundo nome
		 *  ser� uma string vazia, j� que s� tem a quebra de linha para ser lida e ser� interpretado como uma linha vazia).
		  * */
		
		String path = new String();
		
		path = ler.nextLine();	
		
		//countingValleysAndMountains(steps, path);		
		
		countingValley(steps, path);
	}

	private static int countingValley(int steps, String path) {
		// TODO Auto-generated method stub
		int countSteps = 0;
		int result = 0;
		boolean valley = false;
		
		char[] charSteps = new char[steps];
		
		charSteps = path.toCharArray();
		
		for(int i = 0; i < steps; i++) {
			if(charSteps[i] == 'U') {
				countSteps++;				
			}
			if (charSteps[i] == 'D') {
				countSteps--;
				if (countSteps <= -1 && valley == false) {
					result++;
					valley = true;
				}
			}
			if (countSteps == 0) {
				valley = false;
				
			}
			System.out.println(countSteps + " valley: " + valley);
		}
		
		System.out.println("Resultado: " + result);
		
		return result;
	}


}
