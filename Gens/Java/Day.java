public class Day {
    
    public static void main(String[] args){       
        Day gioCompleanno = new Day();
        Day today = new Day();
        System.out.print("Today: ");
        System.out.println(today.toString());
        int daysAlive = today.daysFrom(gioCompleanno);
        System.out.print("Days alive: ");
        System.out.println(daysAlive);
    }    
}