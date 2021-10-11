rule clip_banker
{
    meta:
    author = "De'Vianney"


    strings:
        $set = "SetClipboardData"
        $get = "GetClipboardData"


    condition:
        $set and $get
}
