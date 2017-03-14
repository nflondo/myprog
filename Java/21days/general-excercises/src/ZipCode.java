import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class ZipCode {
	private int zipCode;
	
	public void setZipCode(String zipCodeIn){
		// enforce 5 digits
		 Pattern pattern = Pattern.compile("\\d{7}");
		 Matcher matcher = pattern.matcher(zipCodeIn);

	      if (matcher.matches()) {
	    	  System.out.println("Valid");
	    	  zipCode = Integer.parseInt(zipCodeIn);
	      }
	      else
	      {
	    	  System.out.println("zip code must be in the form XXXXXXX");
	      }
		 
		 
		
	}
	
		
}
