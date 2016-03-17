using System;
using System.Collections.Generic;

namespace Program
{
    abstract class CommonPool
    {
        public int NumReq { get; protected set; }
        public int MaxSize { get; protected set; }
        public bool IsFull { get { return NumReq == MaxSize; } }
        public bool IsEmpty { get { return NumReq == 0; } }
        public virtual void AddReq(Request req){}
        public virtual bool RemoveReq(out Request req){req = new Request(); return false;}
    }

    abstract class Queue : CommonPool
    {
        protected int FirstReq { get; set; }
        protected int LastReq { get; set; }

        public Queue()
        {
            MaxSize = 5;
            FirstReq = 0;
            LastReq = -1;
        }
    }

    sealed class QueueArr : Queue
    {
        public new Request[] Pool;

        public QueueArr()
        {
            MaxSize = 5;
            Pool = new Request[MaxSize];
            NumReq = 0;
        }

        public QueueArr(int _MaxSize)
        {
            MaxSize = _MaxSize;
            Pool = new Request[MaxSize];
            NumReq = 0;
        }

        public override void AddReq(Request req)
        {
            if (IsFull) return;
            NumReq++;
            LastReq = (LastReq + 1) % MaxSize;
            Pool[LastReq] = req;
        }

        public override bool RemoveReq(out Request req)
        {
          	req = new Request();
            if (IsEmpty) return false;
          	NumReq--;
            req = Pool[FirstReq];
            FirstReq = (FirstReq + 1) % MaxSize;
            return true;
        }
    }

    sealed class QueueLst : Queue
    {
        public new List<Request> Pool;

        public QueueLst()
        {
            MaxSize = 5;
            NumReq = 0;
            Pool = new List<Request>();
        }

        public QueueLst(int _MaxSize)
        {
            MaxSize = _MaxSize;
            NumReq = 0;
            Pool = new List<Request>();
        }

        public override void AddReq(Request req)
        {
            if (IsFull) return;
            Pool.Add(req);
            NumReq++;
            LastReq += 1;
        }

        public override bool RemoveReq(out Request req)
        {
            req = new Request();
            if (IsEmpty) return false;
            NumReq--;
            req = Pool[FirstReq];
            Pool.RemoveAt(FirstReq);
            LastReq -= 1;
            return true;
        }
    }

    abstract class Stack : CommonPool
    {
        protected int LastReq { get; set; }
        public Stack()
        {
            MaxSize = 5;
            LastReq = -1;
        }
    }

    sealed class StackArr : Stack
    {
        public new Request[] Pool;

        public StackArr()
        {
            MaxSize = 5;
            Pool = new Request[MaxSize];
            NumReq = 0;
        }

        public StackArr(int _MaxSize)
        {
            MaxSize = _MaxSize;
            Pool = new Request[MaxSize];
            NumReq = 0;
        }

        public override void AddReq(Request req)
        {
            if (IsFull) return;
            NumReq++;
            LastReq = (LastReq + 1) % MaxSize;
            Pool[LastReq] = req;
        }

        public override bool RemoveReq(out Request req)
        {
          	req = new Request();
            if (IsEmpty) return false;
          	NumReq--;
            req = Pool[LastReq];
            LastReq = (LastReq - 1) % MaxSize;
            return true;
        }
    }

    sealed class StackLst : Stack
    {
        public new List<Request> Pool;

        public StackLst()
        {
            MaxSize = 5;
            NumReq = 0;
            Pool = new List<Request>();
        }

        public StackLst(int _MaxSize)
        {
            MaxSize = _MaxSize;
            NumReq = 0;
            Pool = new List<Request>();
        }

        public override void AddReq(Request req)
        {
            if (IsFull) return;
            Pool.Add(req);
            NumReq++;
            LastReq += 1;
        }

        public override bool RemoveReq(out Request req)
        {
            req = new Request();
            if (IsEmpty) return false;
            NumReq--;
            req = Pool[LastReq];
            Pool.RemoveAt(LastReq);
            LastReq -= 1;
            return true;
        }
    }

    sealed class Request
    {
      public Request(){}
      public Request(int req)
      {
          request = req;
      }
      public int request { get; set; }
    }

    public class Program
    {
        public static void Main(string[] args)
        {
          QueueArr q = new QueueArr();

          Request r1 = new Request(1);
          q.AddReq(r1);

          Request r = new Request();
          if (q.RemoveReq(out r)) Console.WriteLine(r.request);

        }
    }
}
