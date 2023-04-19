# cpu-scheduling-Algorithms-
FCFS,SJF,ROUND ROBIN,PRIORITY SHEDULING ALGORITHMS 


1)FCFS CPU SCHEDULLING-FIRST COME FIRST SERVE SCHEDULING ALGORITHMS CPU SCHEDULLING :-
  FCFS (First-Come, First-Served) is a simple CPU scheduling algorithm that executes processes in the order they arrive. 
  The first process that arrives gets the CPU first and runs until it finishes or gets blocked by I/O.
  Other processes have to wait in a queue until the CPU is available. FCFS is easy to understand and implement but can lead to long waiting times and is not
  suitable for real-time systems.
  
 2)SJF CPU SCHEDULLING -SHORTEST JOB FIRST CPU SCHEDULLING :-
    SJF (Shortest Job First) is a CPU scheduling algorithm that selects the process with the shortest burst time to execute first.
    This algorithm aims to minimize the average waiting time of processes by prioritizing the shortest jobs. It can be preemptive or non-preemptive. 
    In preemptive SJF, if a new process arrives with a shorter burst time than the currently executing process, the CPU is given to the new process. 
    In non-preemptive SJF, the current process is allowed to complete its CPU burst before the next process is selected. SJF is a highly efficient algorithm in terms
    of average waiting time but requires knowledge of the burst time of all processes in advance, which may not always be available in practical scenarios.
    
3)ROUND ROBIN CPU SCHEDULLING:-
    Round Robin is a CPU scheduling algorithm that assigns a fixed time quantum or time slice to each process in a cyclic order. The CPU executes each process for
    a time slice and then moves to the next process in the queue, even if the previous process has not finished executing. If a process completes its execution within 
    the time quantum, it is removed from the queue. The algorithm ensures that all processes get a fair share of CPU time, and no process is left waiting indefinitely.
    The time quantum is typically small, which can lead to high context switching overheads, and the algorithm is not suitable for real-time systems. However,
    it is widely used in interactive systems where users expect fast response times.
    
4)PRIORITY CPU SCHEDULLING :-
    Priority CPU scheduling is a scheduling algorithm that assigns a priority to each process and gives the CPU to the process with the highest priority.
    The priority can be set based on various factors such as the amount of CPU time required, the deadline of the process, or the importance of the process.
    The higher the priority, the sooner the process will be executed. In priority scheduling, a process with a higher priority can preempt a running process with a 
    lower priority. This algorithm can be both preemptive and non-preemptive. In preemptive priority scheduling, a process with a higher priority can interrupt a
    lower priority process that is currently executing. In non-preemptive priority scheduling, the current process is allowed to complete its CPU burst before the next
    process with higher priority is selected. Priority scheduling is commonly used in real-time systems and systems with specific requirements, but it can lead to 
    starvation of low-priority processes.
