#include "RemoveIfStatementCheck.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang::tidy::readability {

void RemoveIfStatementCheck::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(stmt(ifStmt(unless(hasElse(stmt())))).bind("remove-if-statement"), this);
}

void RemoveIfStatementCheck::check(const MatchFinder::MatchResult &Result) {
  const auto *MatchedDecl = Result.Nodes.getNodeAs<IfStmt>("remove-if-statement");
  // Get range
  auto Range = MatchedDecl->getSourceRange();
  // Remove the if statement
  std::string Replacement = "; /* [MUTATION][RIS] Removed if statement */";
  diag(Range.getBegin(), "[MUTATION][RIS] If Statement was removed")
      << FixItHint::CreateReplacement(Range, Replacement);
}

} // namespace clang::tidy::readability
