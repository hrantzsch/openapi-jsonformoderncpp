package com.nexenio.CppModernJson;

import io.swagger.v3.oas.models.media.ArraySchema;
import io.swagger.v3.oas.models.media.Schema;
import java.util.*;
import org.apache.commons.lang3.StringUtils;
import org.openapitools.codegen.*;
import org.openapitools.codegen.languages.AbstractCppCodegen;
import org.openapitools.codegen.utils.ModelUtils;

public class CppModernJsonGenerator extends AbstractCppCodegen implements CodegenConfig {
  // TODO this will allow us to change the include path of json.h as an option
  public static final String DEFAULT_INCLUDE = "defaultInclude";

  // source folder where to write the files
  protected String sourceFolder = "src";
  protected String apiVersion = "1.0.0";
  protected String defaultInclude = "#include <nlohmann/json.h>";

  /**
   * Configures the type of generator.
   *
   * @return the CodegenType for this generator
   * @see org.openapitools.codegen.CodegenType
   */
  public CodegenType getTag() {
    return CodegenType.SCHEMA;
  }

  /**
   * Configures a friendly name for the generator. This will be used by the generator to select the
   * library with the -g flag.
   *
   * @return the friendly name for the generator
   */
  public String getName() {
    return "cpp-modern-json";
  }

  /** Provides an opportunity to inspect and modify operation data before the code is generated. */
  @SuppressWarnings("unchecked")
  @Override
  public Map<String, Object> postProcessOperationsWithModels(
      Map<String, Object> objs, List<Object> allModels) {
    // to try debugging your code generator:
    // set a break point on the next line.
    // then debug the JUnit test called LaunchGeneratorInDebugger

    Map<String, Object> results = super.postProcessOperationsWithModels(objs, allModels);

    Map<String, Object> ops = (Map<String, Object>) results.get("operations");
    ArrayList<CodegenOperation> opList = (ArrayList<CodegenOperation>) ops.get("operation");

    // iterate over the operation and perhaps modify something
    for (CodegenOperation co : opList) {
      // example:
      // co.httpMethod = co.httpMethod.toLowerCase();
    }

    return results;
  }

  /**
   * Returns human-friendly help for the generator. Provide the consumer with help tips, parameters
   * here
   *
   * @return A string value for the help message
   */
  public String getHelp() {
    return "Generates a cpp-modern-json client library.";
  }

  public CppModernJsonGenerator() {
    super();

    // set the output folder here
    outputFolder = "generated-code/cpp-modern-json";

    /**
     * Models. You can write model files using the modelTemplateFiles map. if you want to create one
     * template for file, you can do so here. for multiple files for model, just put another entry
     * in the `modelTemplateFiles` with a different extension
     */
    modelTemplateFiles.put("model.mustache", ".h");

    /**
     * Template Location. This is the location which templates will be read from. The generator will
     * use the resource stream to attempt to read the templates.
     */
    templateDir = "cpp-modern-json";

    /** Model Package. Optional, if needed, this can be used in templates */
    modelPackage = "org.openapitools.model";

    /** Reserved words. Override this with reserved words specific to your language */
    reservedWords =
        new HashSet<String>(
            // Arrays.asList(
            //   "sample1",  // replace with static values
            //   "sample2")
            );

    /**
     * Additional Properties. These values can be passed to the templates and are available in
     * models, apis, and supporting files
     */
    // from template
    additionalProperties.put("apiVersion", apiVersion);

    // from Alex
    additionalProperties.put("modelNamespaceDeclarations", modelPackage.split("\\."));
    additionalProperties.put("modelNamespace", modelPackage.replaceAll("\\.", "::"));

    /**
     * Supporting Files. You can write single files for the generator with the entire object tree
     * available. If the input file has a suffix of `.mustache it will be processed by the template
     * engine. Otherwise, it will be copied
     */
    // (<file>, <destination folder relative to `outputFolder`>, <target filename>)
    supportingFiles.add(new SupportingFile("nlohmann/json.hpp", "nlohmann", "json.hpp"));
    supportingFiles.add(new SupportingFile("serialization.mustache", "", "serialization.h"));
    supportingFiles.add(new SupportingFile("test.cpp", "", "test.cpp"));

    /**
     * Language Specific Primitives. These types will not trigger imports by the client generator
     */
    languageSpecificPrimitives =
        new HashSet<String>(
            Arrays.asList("int", "char", "bool", "long", "float", "double", "int32_t", "int64_t"));

    typeMapping = new HashMap<String, String>();
    typeMapping.put("string", "std::string");
    typeMapping.put("array", "std::vector");
    typeMapping.put("map", "std::map");

    typeMapping.put("integer", "int32_t");
    typeMapping.put("long", "int64_t");
    typeMapping.put("number", "double");
    typeMapping.put("boolean", "bool");

    super.importMapping = new HashMap<String, String>();
    importMapping.put("std::vector", "#include <vector>");
    importMapping.put("std::map", "#include <map>");
    importMapping.put("std::string", "#include <string>");
  }

  @Override
  public void processOpts() {
    super.processOpts();

    if (additionalProperties.containsKey(DEFAULT_INCLUDE)) {
      defaultInclude = additionalProperties.get(DEFAULT_INCLUDE).toString();
    }

    // if (additionalProperties.containsKey(RESERVED_WORD_PREFIX_OPTION)) {
    //     reservedWordPrefix = (String) additionalProperties.get(RESERVED_WORD_PREFIX_OPTION);
    // }

    additionalProperties.put("modelNamespaceDeclarations", modelPackage.split("\\."));
    additionalProperties.put("modelNamespace", modelPackage.replaceAll("\\.", "::"));
    additionalProperties.put(
        "modelHeaderGuardPrefix", modelPackage.replaceAll("\\.", "_").toUpperCase(Locale.ROOT));
    additionalProperties.put("defaultInclude", defaultInclude);
    //     // additionalProperties.put(RESERVED_WORD_PREFIX_OPTION, reservedWordPrefix);
  }

  /**
   * Escapes a reserved word as defined in the `reservedWords` array. Handle escaping those terms
   * here. This logic is only called if a variable matches the reserved words
   *
   * @return the escaped term
   */
  @Override
  public String escapeReservedWord(String name) {
    return "_" + name; // add an underscore to the name
  }

  /**
   * Location to write model files. You can use the modelPackage() as defined when the class is
   * instantiated
   */
  public String modelFileFolder() {
    return outputFolder;
    // return outputFolder + "/" + sourceFolder + "/" + modelPackage().replace('.',
    // File.separatorChar);
  }

  @Override
  public String getSchemaType(Schema p) {
    String openAPIType = super.getSchemaType(p);
    String type = null;
    if (typeMapping.containsKey(openAPIType)) {
      type = typeMapping.get(openAPIType);
      if (languageSpecificPrimitives.contains(type)) return toModelName(type);
    } else type = openAPIType;
    return toModelName(type);
  }

  @Override
  public String toModelImport(String name) {
    if (importMapping.containsKey(name)) {
      return importMapping.get(name);
    } else {
      return "#include \"" + toModelFilename(name) + ".h\"";
    }
  }

  @Override
  public CodegenModel fromModel(String name, Schema model) {
    CodegenModel codegenModel = super.fromModel(name, model);

    Set<String> oldImports = codegenModel.imports;
    codegenModel.imports = new HashSet<>();
    for (String imp : oldImports) {
      String newImp = toModelImport(imp);
      if (!newImp.isEmpty()) {
        codegenModel.imports.add(newImp);
      }
    }

    return codegenModel;
  }

  /**
   * Enum name for a property. This is used to set datatypeWithEnum
   *
   * @return the capitalized `name` of the property
   */
  @Override
  public String toEnumName(CodegenProperty property) {
    return StringUtils.capitalize(property.name);
  }

  /**
   * Optional - type declaration. This is a String which is used by the templates to instantiate
   * your types. There is typically special handling for different property types
   *
   * @return a string value used as the `dataType` field for model templates, `returnType` for api
   *     templates
   */
  @Override
  public String getTypeDeclaration(Schema p) {
    String openAPIType = getSchemaType(p);

    if (ModelUtils.isArraySchema(p)) {
      ArraySchema ap = (ArraySchema) p;
      Schema inner = ap.getItems();
      return getSchemaType(p) + "<" + getTypeDeclaration(inner) + ">";
    }
    if (ModelUtils.isMapSchema(p)) {
      Schema inner = ModelUtils.getAdditionalProperties(p);
      return getSchemaType(p) + "<std::string, " + getTypeDeclaration(inner) + ">";
    } else if (ModelUtils.isByteArraySchema(p)) {
      return "std::string";
    }
    if (ModelUtils.isStringSchema(p)
        || ModelUtils.isDateSchema(p)
        || ModelUtils.isDateTimeSchema(p)
        || ModelUtils.isFileSchema(p)
        || languageSpecificPrimitives.contains(openAPIType)) {
      return toModelName(openAPIType);
    }

    return openAPIType;
  }

  /**
   * override with any special text escaping logic to handle unsafe characters so as to avoid code
   * injection
   *
   * @param input String to be cleaned up
   * @return string with unsafe characters removed or escaped
   */
  @Override
  public String escapeUnsafeCharacters(String input) {
    // TODO: check that this logic is safe to escape unsafe characters to avoid code injection
    return input;
  }

  /**
   * Escape single and/or double quote to avoid code injection
   *
   * @param input String to be cleaned up
   * @return string with quotation mark removed or escaped
   */
  public String escapeQuotationMark(String input) {
    // TODO: check that this logic is safe to escape quotation mark to avoid code injection
    return input.replace("\"", "\\\"");
  }
}
