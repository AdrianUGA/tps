package fr.univ_lyon1.info.m1.balleauprisonnier_fx;

public enum Team {
	BLUE("blue"), GREEN("green"), ORANGE("orange"), PURPLE("purple"), YELLOW("yellow"), RED("red");
	
	String color;
	private Team(String color) {
		this.color = color;
	}
	
	public String toString() {
		return this.color;
	}
}
