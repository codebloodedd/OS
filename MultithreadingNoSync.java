import java.util.*;

class TicketBooking implements Runnable{
    int tickets = 1;
    public void run(){
        System.out.println("Waiting for booking ticket for "+ Thread.currentThread().getName());
        if(tickets>0){
            System.out.println("Booking tickets for "+ Thread.currentThread().getName());
            try {
                Thread.sleep(2000);
            } catch (Exception e) {}
            tickets--;
            System.out.println("Tickets booked!! Available Tickets are: "+ tickets);
        }
    }
}

public class MultithreadingNoSync {
    public static void main(String[] args) {
        TicketBooking obj = new TicketBooking();
        Thread t1 = new Thread(obj, "P1");
        Thread t2 = new Thread(obj, "P2");
        t1.start();
        t2.start();
    }
}