#include "pch.h"
#include "StructDeclaration.h"

namespace NativeScript {
namespace Metadata {

using namespace std;
using namespace Microsoft::WRL;

// TODO
namespace {

vector<FieldDeclaration> makeFieldDeclarations(ComPtr<IMetaDataImport2> metadata, mdTypeDef token) {
    HCORENUM enumerator{nullptr};
    ULONG count{0};
    array<mdFieldDef, 1024> tokens;

    ASSERT_SUCCESS(metadata->EnumFields(&enumerator, token, tokens.data(), tokens.size(), &count));
    ASSERT(count < tokens.size() - 1);
    metadata->CloseEnum(enumerator);

    vector<FieldDeclaration> result;
    for (size_t i = 0; i < count; ++i) {
        FieldDeclaration field{metadata, tokens[i]};

        if (!field.isExported()) {
            continue;
        }

        result.push_back(move(field));
    }

    return result;
}

}

StructDeclaration::StructDeclaration(ComPtr<IMetaDataImport2> metadata, mdTypeDef token)
    : Base(metadata, token)
      , _fields(makeFieldDeclarations(metadata, token)) {

}

size_t StructDeclaration::size() const {
    return _fields.size();
}

StructDeclaration::FieldIterator StructDeclaration::begin() const {
    return _fields.begin();
}

StructDeclaration::FieldIterator StructDeclaration::end() const {
    return _fields.end();
}

}
}
