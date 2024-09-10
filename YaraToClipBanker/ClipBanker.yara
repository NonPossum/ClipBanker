rule clip_banker
{
    meta:
    author = "Transyl"


    strings:
        $set = "SetClipboardData"
        $get = "GetClipboardData"


    condition:
        $set and $get
}
