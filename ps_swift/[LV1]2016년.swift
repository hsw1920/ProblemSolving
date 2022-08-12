func solution(_ a:Int, _ b:Int) -> String {
    let d = ["FRI","SAT","SUN","MON","TUE","WED","THU"]
    let month = [31,29,31,30,31,30,31,31,30,31,30,31]
    var sum = 0
    for i in 0..<a-1 {
        sum += month[i]
    }
    sum+=(b-1)
    return d[sum%7]
}