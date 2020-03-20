struct MaxQueue {
  queue<ll> q;
  deque<ll> mq;
  void push(ll a) {
    q.push(a);
    while(!mq.empty() && a > mq.back()) mq.pop_back();
    mq.push_back(a);
  }
  void pop() {
    if (mq.front() == q.front()) mq.pop_front();
    q.pop();
  }
  ll front() {
    return q.front();
  }
  ll max() {
    return mq.front();
  }
  ll size() {
    return q.size();
  }
  bool empty() {
    return q.empty();
  }
};
