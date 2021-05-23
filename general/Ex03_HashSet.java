package hackerRank.general;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/*
Link:
https://www.hackerrank.com/challenges/java-hashset/problem?h_r=profile

Sample Input
5 
john tom
john mary
john tom
mary anna
mary anna
 */

public class Ex03_HashSet {

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        String [] pair_left = new String[t];
        String [] pair_right = new String[t];
        
        for (int i = 0; i < t; i++) {
            pair_left[i] = s.next();
            pair_right[i] = s.next();
        }        
        
        resolve(pair_left, pair_right, t);        

	}

	private static void resolve(String[] pair_left, String[] pair_right, int t) {
		 Set<String> lista = new HashSet<String>();
		 String nome = new String();		 
		 
		 for (int i = 0; i < t; i ++) {
			 nome = pair_left[i].concat(" ").concat(pair_right[i]);
			 lista.add(nome);
			 System.out.println(lista.size());
			 
		 }
		 
	
	}
}
