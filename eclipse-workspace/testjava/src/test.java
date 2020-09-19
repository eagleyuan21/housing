public class test{
	
	public static void main(String[] args) {
	String[] rank = {"jack", "queen", "king"};
    String[] suit = {"blue", "red"};
    int[] pointValue = {11, 12, 13};
    Deck d = new Deck(rank, suit, pointValue);
    d.deal();
    System.out.println(d);
	}
}