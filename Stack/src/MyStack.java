import java.util.EmptyStackException;

public class MyStack<E>{
        private int maxSize;
        private E[] stackArray;
        private int top;

        public MyStack(int s) {
            maxSize = s;
            stackArray = (E[]) new Object[maxSize];
            top = -1;
        }
        public void push(E j) {
            if(isFull())
                return;
            stackArray[++top] = j;
        }
        public E pop() throws EmptyStackException {
            if (isEmpty()){
                throw new EmptyStackException();
            } else{
                return stackArray[top--];
            }
        }
        public void peek() {
            System.out.println("top: " + stackArray[top]);
        }
        public boolean isEmpty() {
            return (top == -1);
        }
        public boolean isFull() {
            return (top == maxSize - 1);
        }

        public void multiPop(int q){
            for(int i = 0; i < q; i++){
                pop();
            }
        }

        public static void main(String[] args) {
            MyStack theStack = new MyStack(10);
            theStack.push(10);
            theStack.push(20);
            theStack.push(30);
            theStack.push(40);

            theStack.multiPop(3);
            theStack.peek();
        }
    }
