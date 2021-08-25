package hackerRank.pagSeguro;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

public class Ex12 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner ler = new Scanner(System.in);		
		String skills = new String();

		//skills = "pcmbzpcmbz";
		//skills = "pcmbz";
		skills = ler.nextLine();
		
		System.out.println(resolve(skills));

	}

	private static int resolve(String skills) {
		// TODO Auto-generated method stub
		
		//converter para vetor de char para poder interar
		char tempArray[] = skills.toCharArray(); 

		// sort tempArray 
		Arrays.sort(tempArray); 

		int[] vet = new int[5];
		for (int i = 0; i < vet.length; i ++) {
			vet[i] = 0;			
		}

		for (int i = 0; i < skills.length(); i ++) {
			if (tempArray[i] == 'p') {
				vet[0] += 1;
			}
			if (tempArray[i] == 'c') {
				vet[1] += 1;
			}
			if (tempArray[i] == 'm') {
				vet[2] += 1;
			}
			if (tempArray[i] == 'b') {
				vet[3] += 1;
			}
			if (tempArray[i] == 'z') {
				vet[4] += 1;
			}
		}

		Arrays.sort(vet);

		return vet[0];

	}

}
