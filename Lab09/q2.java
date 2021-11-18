public class q2 {
	public static int num = 0;
	public static void main(String argv[]) {
		int iter = 250000;
		q2_2 h1 = new q2_2(iter);
		Thread th1 = new Thread(h1);
		q2_2 h2 = new q2_2(iter);
                Thread th2 = new Thread(h2);
		q2_2 h3 = new q2_2(iter);
                Thread th3 = new Thread(h3);
		q2_2 h4 = new q2_2(iter);
                Thread th4 = new Thread(h4);

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
		catch(InterruptedException e) {
			System.err.println(e);
		}

		System.out.println("Done! total num is "+num);
	}
}

class q2_2 extends Thread {
	int iter;

	public q2_2(int i) {
		iter = i;
	}

	public void run() {
		for(int i = 0; i < iter; i++) {
			q2.num++;
		}
		System.out.println("Thread ID "+Thread.currentThread().getName()+", num is "+q2.num);
	}
}
