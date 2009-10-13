use inc::Module::Install;

my $e = env_for_c(CPPPATH => 'extlib');
$e->test('t/01_simple', 't/01_simple.cc');

tests 't/*.t';

WriteMakefileForC;
