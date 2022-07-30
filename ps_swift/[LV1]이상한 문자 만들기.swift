func isLower(_ c: String)-> Bool {
    if c>="a" && c<="z" {
        return true
    }
    return false
}

func solution(_ s:String) -> String {
    var res: [String] = []
    var len = s.count
    var idx = 0
    for i in s {
        if idx % 2 == 0 {
            res.append(String(i.uppercased()))
        }
        else {
            res.append(String(i.lowercased()))
        }
        idx+=1
        if i == " " {
            idx = 0
        }
    }
    print(res.joined())
    return res.joined()
}