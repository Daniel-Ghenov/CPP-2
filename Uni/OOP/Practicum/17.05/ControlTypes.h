#include "Controll.h"

class Label: Controll{
private:
    String _data;

public:
    Label() = default;
    Label(const String& data, const String& name, size_t size, size_t location);
    void setDataDialog() override;

};

class CheckBox: Controll{
private:
    bool isChecked = false;
public:

    CheckBox() = default;
    CheckBox(bool checked, const String& name, size_t size, size_t location);
    void setDataDialog() override;

};