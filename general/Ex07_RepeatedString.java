package hackerRank.general;

import java.util.Scanner;

public class Ex07_RepeatedString {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner ler = new Scanner(System.in);
		
		String s = ler.nextLine();		
		long n = ler.nextInt();
		int countA = 0;
		
		//não existe o método repeatString no java;
		
		//como contar aquantidade de letra 'a' que aparece em uma String		
		for(char c : s.toCharArray()) {
			if (c == 'a') {
				countA ++;
			}
		}		
		System.out.println(countA);
		
		//como repetir uma String n vezes
		System.out.println(s.repeat(3)); //Ex: repetir a string s 3 vezes
		
		
		
		
		
		
		
		
		

	}

}
