func solution(_ phone_number:String) -> String {
    var str = ""
    var size=phone_number.count
    for i in 0..<size-4{
        str+="*"
    }
    str+=phone_number.suffix(4)
    return str
}