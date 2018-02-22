
public class MCSAAnswer extends MCAnswer {
	
	//Constructor
	public MCSAAnswer(String text, double creditIfSelected) {
		
		super(text, creditIfSelected);
	}
	//------------------------------------------------------------------------------------------------------------


	//Print the Answer
	public void print() {
		
		System.out.printf("%s", text);
	}

	//------------------------------------------------------------------------------------------------------------

	//Get credit
	public double getCredit(Answer rightAnswer) {
		
		if (this.equals(rightAnswer)) {
			
			return creditIfSelected; //Returns the amount of credit we give the student if they get it right
		}
			
		else 
			return 0;
		
	}
	
	//------------------------------------------------------------------------------------------------------------

	//I need this function to be able to compare the answers with student answers to give credit.
	public String getText() { 
		
		return text;
	}


	//------------------------------------------------------------------------------------------------------------
	//Sets question as selected
	public void setSelected(boolean selected) {
 
		this.selected=selected;
	}
}
