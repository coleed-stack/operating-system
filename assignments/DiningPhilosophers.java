import java.util.concurrent.locks.ReentrantLock;

public class DiningPhilosophers {

    static long startTime = System.nanoTime();
    public static void main(String[] args) throws Exception {

        System.out.println(startTime);

        final Philosopher[] philosophers = new Philosopher[5];
        Chopstick[] forks = new Chopstick[philosophers.length];

        for (int i = 0; i < forks.length; i++) {
            forks[i] = new Chopstick();
        }

        for (int i = 0; i < philosophers.length; i++) {
            Chopstick left = forks[i];
            Chopstick right = forks[(i + 1) % forks.length];

            if (i == philosophers.length - 1) {
                
                // The last philosopher picks up the right fork first
                philosophers[i] = new Philosopher(right, left, 0); 
            } else {
                philosophers[i] = new Philosopher(left, right, 0);
            }
            
            Thread t 
              = new Thread(philosophers[i], "Philosopher " + (i + 1));
            t.start();
        }
    }

    static class Chopstick {
        private final ReentrantLock lock = new ReentrantLock();

        public void aquire() throws InterruptedException{
                lock.lockInterruptibly();
        }

        public void release() {
            lock.unlock();
        }
    }

    public static class Philosopher implements Runnable {

        // The forks on either side of this Philosopher 
        private Chopstick left;
        private Chopstick right;
        private int eatCount;
        boolean hungry = true;

        public Philosopher(Chopstick left, Chopstick right, int eatCount) {
            this.left = left;
            this.right = right;
            this.eatCount = eatCount;
        }

        @Override
        public void run() {
            try {
                while (hungry == true) {
                    
                    // thinking
                    System.out.println((System.nanoTime() - startTime) + " " + Thread.currentThread().getName() + " is thinking");
                    Thread.sleep(((int) (Math.random() * 100)));

                    left.aquire();
                    try {
                        System.out.println((System.nanoTime() - startTime) + " " + Thread.currentThread().getName() + " picked up left fork");
                        Thread.sleep(((int) (Math.random() * 100)));

                        right.aquire();
                        try {
                            // eating
                            System.out.println((System.nanoTime() - startTime) + " " + Thread.currentThread().getName() + " picked up right fork and is eating"); 
                            Thread.sleep(((int) (Math.random() * 100)));

                            eatCount++;
                            if (eatCount >= 2) {
                                hungry = false;
                            }

                            System.out.println((System.nanoTime() - startTime) + " " + Thread.currentThread().getName() + " put down right fork");   
                            Thread.sleep(((int) (Math.random() * 100)));

                        } finally {
                            right.release();
                        }
                        
                        // Back to thinking
                        System.out.println((System.nanoTime() - startTime) + " " + Thread.currentThread().getName() + " put down left fork and is thinking");
                        Thread.sleep(((int) (Math.random() * 100)));

                    } finally {
                        left.release();
                    }
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return;
            }
        }

    }
}
