func solution(_ s:String, _ n:Int) -> String {
    var lower = Array("abcdefghijklmnopqrstuvwxyz")
    var upper = Array("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    var res :[String] = []
    var arr = Array(s)
    for i in 0..<arr.count {
        //소문자, 대문자
        if lower.contains(arr[i]) {
            let index = (lower.firstIndex(of: arr[i])!+n)%26
            arr[i] = lower[index]
        }
        else if upper.contains(arr[i]) {
            let index = (upper.firstIndex(of: arr[i])!+n)%26
            arr[i] = upper[index]
        }
    }
    return String(arr)
}