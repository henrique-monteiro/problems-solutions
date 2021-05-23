package hackerRank.pagSeguro;

public class Ex13 {
	
	public static String isPossible(int a, int b, int c, int d) {
	    // Write your code here
	    for(int i = 0; i < 1000; i++){
	        if ((a + b) <= c){
	            a = a + b;
	        }
	        else if((a + b) <= d) {
	            b = a + b;
	        }        
	    }
	    
	    if ((a == c) && (b == d)){
	        return "Yes";
	    }
	   
	    return "No";

	    }

}
