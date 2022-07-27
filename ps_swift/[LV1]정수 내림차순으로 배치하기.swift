func solution(_ n:Int64) -> Int64 {
    var str = String(n)
    var arr = str.map{$0}
    arr.sort{$0 > $1}
    var tmp = ""
    for i in 0..<arr.count {
        tmp += String(arr[i])
    }
    return Int64(tmp)!
}