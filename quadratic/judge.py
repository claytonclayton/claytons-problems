from judging.judge_utils import judge_program_all_or_nothing

def judge(their_answer, language):
    return judge_program_all_or_nothing(__file__, their_answer, language)
