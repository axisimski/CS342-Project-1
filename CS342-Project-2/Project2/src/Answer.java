//Alexander Simeonovski,
//asimeono

public abstract class Answer{
 
	
	protected Answer(String n) {		
        System.out.println("foo");
	};
	


	abstract void print();	
	
 	abstract double getCredit(Answer rightAnswer);
	
}

//==========================================================================================

class  MCAnswer extends Answer {
	


	protected String text;
	protected Boolean checked;
	protected double creditIfSelected;
	
	protected MCAnswer(String text, double creditIfSelected) {
		super(text);
 	} 	
	
	 
	
	void print() {
		
		System.out.printf("%s\n", text);
	}
		

	@Override
	double getCredit(Answer rightAnswer) {
		
		return creditIfSelected;		
		
	}
	
	
	public Boolean setChecked(Boolean checked) {
		this.checked = checked;
		return checked;
	}	

}

//==========================================================================================

class  MCSAAnswer extends MCAnswer{

	protected MCSAAnswer(String text, double creditIfSelected) {
		super(text, creditIfSelected);
	}
	 
		
	double getCredit(Answer rightAnswer) {
		
		return creditIfSelected;		
		
	}
	
} 

class  SAAnswer extends Answer{

	protected String text;
	
	protected SAAnswer(String n) {
		super(n);
 	}
	
	
	void print() {		
		System.out.printf("%s\n", text);
	}
	
	
	@Override
	double getCredit(Answer rightAnswer) {
		
		return  (double) 1111;		
		
	}
	
	
	
}

















