#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "codeeditor.h"

#include <QObject>
#include <QDir>

class Property
{

public:
    QString name;
    QString text;

    Property(QString name, QString text);
};

/**
 * @brief The FileSystem class handles all file related operations, including execution of mCRL2 tools
 */
class FileSystem : public QObject
{
    Q_OBJECT

public:    
    /**
     * @brief FileSystem Constructor
     * @param specificationEditor The specification editor in the main window
     * @parent The main widget (main window)
     */
    explicit FileSystem(CodeEditor *specificationEditor, QWidget *parent);

    /**
     * @brief makeSureProjectFolderExists Checks whether the projects folder exists, if not creates it
     */
    void makeSureProjectsFolderExists();

    /**
     * @brief makeSureProjectFolderExists Checks whether the project folder exists, if not creates it
     */
    void makeSureProjectFolderExists();

    /**
     * @brief makeSureProjectFolderExists Checks whether the properties folder exists, if not creates it
     */
    void makeSurePropertiesFolderExists();

    /**
     * @brief projectFolderPath Defines the file path of the current project folder
     * @param projectName The name of the current project
     * @return The file path of the project folder
     */
    QString projectFolderPath(QString projectName);

    /**
     * @brief propertiesFolderPath Defines the file path of the current properties folder
     * @param projectName The name of the current project
     * @return The file path of the properties folder
     */
    QString propertiesFolderPath(QString projectName);

    /**
     * @brief specificationFilePath Defines the file path of a specification
     * @return The file path of the specification
     */
    QString specificationFilePath();

    /**
     * @brief lpsFilePath Defines the file path of a lps
     * @return The file path of the lps
     */
    QString lpsFilePath();

    /**
     * @brief propertyFilePath Defines the file path of a property
     * @param propertyName The name of the property
     * @return The file path of the property
     */
    QString propertyFilePath(QString propertyName);

    /**
     * @brief pbesFilePath Defines the file path of a pbes
     * @param propertyName The name of the property this pbes correspeonds to
     * @return The file path of the pbes
     */
    QString pbesFilePath(QString propertyName);

    /**
     * @brief getExecutablesFolder Gets the folder containing the mCRL2 tool executables
     * @return The folder with the executables
     */
    const QDir *getExecutablesFolder();

    /**
     * @brief projectOpened Checks whether a project is opened
     * @return Whether a project is opened
     */
    bool projectOpened();

    /**
     * @brief getCurrentSpecification Gets the specification that is in the specification editor
     * @return the current specification ion the specification editor
     */
    QString getCurrentSpecification();

    /**
     * @brief specificationModified Checks whether the specification has been modified since it has been saved
     * @return Whether the specification has been modified since it has been saved
     */
    bool isSpecificationModified();

    /**
     * @brief propertyModified Checks whether the property has been modified since it has been saved
     * @param propertyName The name of the property
     * @return Whether the property has been modified since it has been saved
     */
    bool isPropertyModified(QString propertyName);

    /**
     * @brief setPropertyModified Sets the property to modified
     * @param PropertyName The name of the property
     */
    void setPropertyModified(QString propertyName);

    /**
     * @brief lpsFileExists Checks whether an lps file exists that is created from the current specification
     * @return Whether an lps file exists that is created from the current specification
     */
    bool upToDateLpsFileExists();

    /**
     * @brief upToDatePbesFileExists Checks whether a pbes file exists that is created from the current specification and property
     * @param propertyName The name of the property
     * @return Whether a pbes file exists that is created from the current specification and property
     */
    bool upToDatePbesFileExists(QString propertyName);

    /**
     * @brief newProject Creates a new project with the corresponding file structure
     * @return An error message if unsuccessful, else the empty string
     */
    QString newProject(QString projectName);

    /**
     * @brief getAllProjects Gets all projects that are in the project folder
     * @return The names of all projects
     */
    QStringList getAllProjects();

    /**
     * @brief openProject Opens the project with the given project name
     * @return The list of the properties that need to be added
     */
    std::list<Property*> openProject(QString projectName);

    /**
     * @brief saveProject Saves the current specification
     */
    void saveSpecification();

    /**
     * @brief saveProperty Saves the given property
     * @param propertyName The name of the property
     * @param propertyText The text of the property
     */
    void saveProperty(Property *property);

public slots:
    /**
     * @brief setSpecificationModified Sets the specification to modified
     */
    void setSpecificationModified();

signals:
    /**
     * @brief modified Is emitted whenever the specification or a property is changed
     */
    void hasChanges(bool changes);


private:
    QString projectsFolderPath = QDir::currentPath() + QDir::separator() + "projects";
    QString propertiesFolderName = "properties";
    QDir *executablesFolder = new QDir("C:\\Users\\s123188\\Documents\\QtProjects\\mCRL2-IDE\\execs");

    QWidget *parent;
    CodeEditor *specificationEditor;
    QString projectName;
    bool projectOpen;

    bool specificationModified;
    std::map<QString, bool> propertymodified;
};

#endif // FILESYSTEM_H
