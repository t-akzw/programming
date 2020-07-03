class Stack
  attr_reader :top, :stack

  def initialize(size)
    @struct_nil = Struct.new("MyNil", :x)
    @size = size
    @stack = arr_new(@size)
    @top = @stack.last
  end

  def clear
    @stack = arr_new(@size)
  end

  # 無理やりサイズ指定でStruct::MyNilクラスで値を埋めて初期化しているので
  #   uniqして残った値のクラスが定義したStruct::MyNilクラスと全て等しければempty
  def is_empty
    @stack.uniq.map {|v| v.class == Struct::MyNil}.count(false) == 0 
  end

  def is_full
    @stack.uniq.map {|v| v.class == Struct::MyNil}.count(false) == @size
  end

  def push(val)
    if is_full
      @stack = arr_new(@size).concat(@stack)
      @size = @stack.size
    end
    @stack.rotate!
    @stack[-1] = val
    @top = @stack.last
  end

  def pop
    val = @stack.pop()
    @stack.unshift(mynil)
    @top = @stack.last
    val
  end

private
  def arr_new(size)
    Array.new(size, mynil)
  end

  def mynil
    @struct_nil.new(nil)
  end
end

s = Stack.new(2)
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



