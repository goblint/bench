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
  // Get locations
  SourceLocation Start = MatchedDecl->getBeginLoc();
  SourceLocation End = MatchedDecl->getEndLoc().getLocWithOffset(1);
  auto Range = CharSourceRange::getCharRange(Start, End);
  // Remove the if statement
  std::string Replacement = "; /* [MUTATION][RIS] Removed if statement */";
  diag(Start, "[MUTATION][RIS] If Statement was removed")
      << FixItHint::CreateReplacement(Range, Replacement);
}

} // namespace clang::tidy::readability
