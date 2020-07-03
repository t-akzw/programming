class Queue
  attr_reader :next, :queue, :front, :tail

  def initialize(size)
    @struct_nil = Struct.new("MyNil", :x)
    @size = size
    @queue = arr_new(@size)
    @front = 0
    @tail = 0
    @next = @queue[front]
  end

  def clear
    @queue = arr_new(@size)
  end

  def is_empty
    @front == @tail
  end

  def is_full
    (@tail + 1) % @size == @front
  end

  def enqueue(val)
    @queue[@tail] = val
    resize
    next_tail # 次のエンキューのためにポインタをずらす
  end

  def dequeue
    unless is_empty
      val = @queue[@front]
      @queue[@front] = mynil
      next_front
      @next = @queue[@front]
      val
    end
  end

private
  def resize
    if is_full
      @queue = @queue[@front..-1].concat(@queue[0..@tail]) if @front > @tail
      @front = 0
      @tail = @size - 1
      @queue.concat(arr_new(@size))
      @size = @queue.size
    end
  end

  def next_tail
    @tail = (@tail + 1 == @size)? 0 : @tail + 1
  end

  def next_front
    @front = (@front + 1 == @size)? 0 : @front + 1
  end

  def arr_new(size)
    Array.new(size, mynil)
  end

  def mynil
    @struct_nil.new(nil)
  end
end

q = Queue.new(2)
q.queue
q.enqueue(1)
x = q.dequeue

s.top
s.is_empty
s.push(1)
s.top
s.is_empty
s.push(2)
s.top
s.pop
s.top
s.clear
s.is_empty?



