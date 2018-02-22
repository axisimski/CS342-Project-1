

public class SAAnswer extends Answer {
	protected String text;

	//Constructor
	public SAAnswer(String text) {
		
		this.text = text;
	}

	
	//Print the answer
	public void print() {
		
		System.out.printf("%s", text);
	}

	
	//get credit for the answer
	public double getCredit(Answer rightAnswer) {
		
		if (this.equals(rightAnswer)) {
			
			
			return 1;
		}
			
		else 
			return 0;
	}


	//Getter
	@Override
	String getText() {
		 
		return text;
	}
}
