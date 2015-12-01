GUIFactory* guiFactory;
const char* styleName = getenv("LOOK_AND_FEEL");

if (strcmp(styleName, "Motif") == 0)
{
    guiFactory = new MotifFactory;
}
else if (strcmp(styleName, "Presentation_Manager") == 0)
{
    guiFactory = new PMFactory;
}
else
{
    guiFactory = new DefaultFactory;
}

