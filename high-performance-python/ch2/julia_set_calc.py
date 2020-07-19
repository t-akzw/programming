import time
from functools import wraps

x1, x2, y1, y2 = -1.8, 1.8, -1.8, 1.8
c_real, c_imag = -0.62772, -0.42193


def calc_pure_python(desired_width, max_iterations):
    """
    複素数の座標リストzsと、複素数のパラメータリストcsを作り、ジュリア集合を作って表示する
    """
    x_step = (float(x2-x1)/float(desired_width))
    y_step = (float(y1-y2)/float(desired_width))
    x = []
    y = []
    ycoord = y2
    while ycoord > y1:
        y.append(ycoord)
        ycoord += y_step
    xcoord = x1
    while xcoord < x2:
        x.append(xcoord)
        xcoord += x_step
    
    # 座標のリストを作り各点を初期状態にする。
    # 初期状態は定数で、容易に削除可能なので、必要ならこの関数に
    # 入力値を与えて実世界のシナリオをシミュレートできる。
    zs = []
    cs = []
    for ycoord in y:
        for xcoord in x:
            zs.append(complex(xcoord, ycoord))
            cs.append(complex(c_real, c_imag))
    
    print("Length of x: {}".format(len(x)))
    print("Total elements: {}".format(len(zs)))
    start_time = time.time()
    output = calclate_z_serial_purepython(max_iterations, zs, cs)
    end_time = time.time()
    secs = end_time - start_time
    func_name = calclate_z_serial_purepython.__name__
    print("{} took {} seconds".format(func_name, secs))
    
    # この合計値は1000^2のグリッドを繰り返し上限を300回とした時の値。
    # 固定入力値を使って、微小な間違いを検出するためのもの。
    assert sum(output) == 33219980


def timefn(fn):
    @wraps(fn)
    def measure_time(*args, **kwargs):
        t1 = time.time()
        result = fn(*args, **kwargs)
        t2 = time.time()
        print("@timefn: {} took {} seconds".format(fn.__name__, str(t2-t1)))
        return result
    return measure_time


@timefn
def calclate_z_serial_purepython(maxiter, zs, cs):
    """ジュリア漸化式を用いてoutputリストを作る"""
    output = [0]*len(zs)
    for i in range(len(zs)):
        n = 0
        z = zs[i]
        c = cs[i]
        while abs(z) < 2 and n < maxiter:
            z = z*z+c
            n += 1
        output[i] = n
    return output


if __name__ == '__main__':
    calc_pure_python(desired_width=1000, max_iterations=300)