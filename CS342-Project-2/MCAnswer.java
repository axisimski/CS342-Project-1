

public abstract class MCAnswer extends Answer {
	
	protected String text;
	protected boolean selected;
	protected double creditIfSelected;

	//Constructor
	protected MCAnswer(String text, double creditIfSelected) {
	
		this.text = text;
		this.selected = false;
		this.creditIfSelected = creditIfSelected;
		
	}
	
	//print fn()
	abstract public void print();
	
	//Selects an answer (sets it to selected) if choosen
	abstract public void setSelected(boolean selected);

}
