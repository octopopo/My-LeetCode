class MyStack {
public:
    /** Initialize your data structure here. */
    //this queue mainly for push
    queue<int> m_queue1;
    //this queue mainly for store
    queue<int> m_queue2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        m_queue1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(m_queue1.empty() && !m_queue2.empty()){
            while(!m_queue2.empty()){
                int temp = m_queue2.front();
                m_queue1.push(temp);
                m_queue2.pop();
            }
        }
        while(m_queue1.size() > 1){
            int temp = m_queue1.front();
            m_queue2.push(temp);
            m_queue1.pop();
        }
        int temp = m_queue1.front();
        m_queue1.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        if(m_queue1.empty() && !m_queue2.empty()){
            while(!m_queue2.empty()){
                int temp = m_queue2.front();
                m_queue1.push(temp);
                m_queue2.pop();
            }
        }
        while(m_queue1.size() > 1){
            int temp = m_queue1.front();
            m_queue2.push(temp);
            m_queue1.pop();
        }
        int temp = m_queue1.front();
        //m_queue1.pop();
        return temp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return m_queue1.empty() && m_queue2.empty();
    }
};