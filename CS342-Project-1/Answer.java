//Alexander Simeonovski,
//asimeono

//The Answer class represents a textual multiple-choice answer

public class Answer {
	
	//private variables as specified in the instructions
	//The string represents a given answer, checked whether it is selected
	//and the value the positive or negative 'points' for selecting it,
	//the default is 0.
	
	private String a;
	private Boolean checked;
	private double value;
 	
	//Answer constructor.
	//Sets, sets the question string by taking a string parameter and calling the setter.
	
	Answer(String n){		
		setA(n); 
		setChecked(false); //Default is unselected
		value=0; //Default value for questions is 0 (If unselected)
	}
	
	//Prints answers based on their order. a) for the first, b) for the second etc...
	
	void print(int n) {		
		if(n==1) {
			System.out.printf("a) %s\n", getA());}
		if(n==2) {
			System.out.printf("b) %s\n", getA());}
		if(n==3) {
			System.out.printf("c) %s\n", getA());}
		if(n==4) {
			System.out.printf("d) %s\n", getA());}
		if(n==5) {
			System.out.printf("e) %s\n", getA());}
	}
	
	//Sets an answer as selected (selects an answer).
	
	void setSelected(Boolean chosen ) {		
		setChecked(chosen);
	}
	
	//Sets how much each question is worth if selected and unselected.
	
	void setValue(double unselected, double selected){    	
		
    	if(setChecked(true)) {    		
    		value=selected;    		
    	}    	
    	else if(setChecked(false)) {
    		value=unselected;
    	}  		   
	}
	
	//Returns the value of the answer
	
	double getValue() {		
		  return value;
	}
	
	//Returns if the answer is selected or not 
	
	public Boolean getChecked() {
		return checked;
	}
	
	//Selects an answer. 
	
	public Boolean setChecked(Boolean checked) {
		this.checked = checked;
		return checked;
	}	
 	 
	//Getter for the answer string
	
	public String getA() {
		return a;
	}
	
	//Setter for the answer string
	
	public void setA(String a) {
		this.a = a;
	}

}
