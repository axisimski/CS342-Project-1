
//Abstract Answer class. All methods are declared, but not implemented
//They are passed on to the children of the class.

abstract class Answer {
 
	//empty constructor
	protected Answer() {
		
	}

	//To print an answer
	abstract void print();		

	//Returns the credit 
	abstract double getCredit(Answer rightAnswer);
	
	//This returns the text string, it is not in the 'instructions'
	//But I found it useful.
	abstract String getText();


}
