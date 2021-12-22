import java.lang.Thread;

public class ex1 {
	public static void main(String[] args) {
		job1 j1 = new job1();
		job2 j2 = new job2();
		Thread th1 = new Thread(j1);
		Thread th2 = new Thread(j2);
		Thread th3 = new Thread(j1);
		Thread th4 = new Thread(j2);
		
		th1.start();
		th2.start();
		th3.start();
		th4.start();
		
		try {
			th1.join();
			th2.join();
			th3.join();
			th4.join();
		}
		catch(InterruptedException e) {} 
		Sync.show();
	}
}

class job1 implements Runnable {
	public synchronized void run() {
		for(int i = 0; i < 25000000; i++) {
			Sync.add();
		}
		System.out.println("Job1 finish!");
		Sync.show();
	}
}

class job2 implements Runnable {
	public synchronized void run() {
		for(int i = 0; i < 25000000; i++) {
			Sync.sub();
		}
		System.out.println("Job2 finish!");
		Sync.show();
	}
}

class Sync {
	private static int count = 0;
	public static synchronized void add() {
		count++;
	}
	public static synchronized void sub() {
		count--;
	}
	public static synchronized void show() {
		System.out.println("Count = "+count);
	}
}
