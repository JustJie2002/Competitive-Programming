

var = dict()
rvar = dict()
while True:
    try:
        s = input()
        if s == "clear":
            var.clear()
            rvar.clear()
            continue
        op, *params = s.split()
        match op:
            case "def":
                v, x = params
                x = int(x)
                if v in var:
                    px = var[v]
                    del var[v]
                    del rvar[px]
                var[v] = x
                rvar[x] = v
            case "calc":
                cur = 0
                ops = 1
                for i, param in enumerate(params):
                    if i & 1:
                        ops = 1
                        if param == "-":
                            ops = -1
                    else:
                        if param not in var:
                            cur = None
                            break
                        cur += ops * var[param]
                res = rvar.get(cur, "unknown")
                params.append(res)
                ans = " ".join(params)
                print(ans)
    except EOFError:
        break